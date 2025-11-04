import db from "../database/db";
import { Device } from "../models/device";

export const registerDevice = (id: string, name?: string): Promise<Device> => {
  return new Promise((resolve, reject) => {
    const now = new Date().toISOString();

    db.get(
      "SELECT * FROM devices WHERE id = ?",
      [id],
      (err: Error | null, row: any) => {
        if (err) return reject(err);

        if (!row) {
          // Novo dispositivo
          db.run(
            "INSERT INTO devices (id, name, registeredAt, lastSeen, commands) VALUES (?, ?, ?, ?, ?)",
            [id, name || null, now, now, JSON.stringify([])],
            (err2) => {
              if (err2) return reject(err2);
              resolve({
                id,
                name,
                registeredAt: new Date(now),
                lastSeen: new Date(now),
                commands: [],
              });
            }
          );
        } else {
          // Já existe, apenas atualiza o lastSeen
          db.run("UPDATE devices SET lastSeen = ? WHERE id = ?", [now, id]);
          resolve({
            id: row.id,
            name: row.name,
            registeredAt: new Date(row.registeredAt),
            lastSeen: new Date(now),
            commands: JSON.parse(row.commands || "[]"),
          });
        }
      }
    );
  });
};

export const getDevice = (id: string): Promise<Device | null> => {
  return new Promise((resolve, reject) => {
    db.get(
      "SELECT * FROM devices WHERE id = ?",
      [id],
      (err: Error | null, row: any) => {
        if (err) return reject(err);
        if (!row) return resolve(null);

        resolve({
          id: row.id,
          name: row.name,
          registeredAt: new Date(row.registeredAt),
          lastSeen: new Date(row.lastSeen),
          status: row.status,
          commands: JSON.parse(row.commands || "[]"),
        });
      }
    );
  });
};

export const saveSensorData = (
  id: string,
  temperature: number,
  humidity: number
) => {
  const now = new Date().toISOString();
  db.run(
    `INSERT INTO sensor_data (deviceId, temperature, humidity, timestamp)
     VALUES (?, ?, ?, ?)`,
    [id, temperature, humidity, now],
    (err) => {
      if (err) console.error("Error saving sensor data:", err);
    }
  );
};

export const addCommand = (id: string, command: string): Promise<void> => {
  return new Promise((resolve, reject) => {
    db.get(
      "SELECT commands FROM devices WHERE id = ?",
      [id],
      (err: Error | null, row: any) => {
        if (err) return reject(err);
        if (!row) return resolve();

        const commands = JSON.parse(row.commands || "[]");
        commands.push(command);

        db.run("UPDATE devices SET commands = ? WHERE id = ?", [
          JSON.stringify(commands),
          id,
        ]);
        resolve();
      }
    );
  });
};

export const fetchCommands = (id: string): Promise<string[]> => {
  return new Promise((resolve, reject) => {
    db.get(
      "SELECT commands FROM devices WHERE id = ?",
      [id],
      (err: Error | null, row: any) => {
        if (err) return reject(err);
        if (!row) return resolve([]);

        const commands = JSON.parse(row.commands || "[]");
        db.run("UPDATE devices SET commands = ? WHERE id = ?", [
          JSON.stringify([]),
          id,
        ]);
        resolve(commands);
      }
    );
  });
};

// Lista todos os dispositivos
export const listDevices = (): Promise<Device[]> => {
  return new Promise((resolve, reject) => {
    db.all("SELECT * FROM devices", [], (err, rows: any) => {
      if (err) return reject(err);
      const devices = (rows || []).map((r: Device) => ({
        id: r.id,
        name: r.name,
        registeredAt: new Date(r.registeredAt),
        lastSeen: new Date(r.lastSeen),
        status: r.status,
        commands: JSON.parse(String(r.commands || "[]")),
      }));
      resolve(devices);
    });
  });
};

// buscar histórico de sensor para um deviceId
export const getSensorData = (
  id: string
): Promise<
  Array<{ temperature: number; humidity: number; timestamp: string }>
> => {
  return new Promise((resolve, reject) => {
    db.all(
      "SELECT temperature, humidity, timestamp FROM sensor_data WHERE deviceId = ? ORDER BY timestamp DESC",
      [id],
      (
        err,
        rows:
          | Array<{ temperature: number; humidity: number; timestamp: string }>
          | undefined
      ) => {
        if (err) return reject(err);
        resolve(rows || []);
      }
    );
  });
};
