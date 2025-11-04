import sqlite3 from "sqlite3";
import path from "path";

const dbPath = path.resolve(process.cwd(), "src", "database", "devices.db");
const db = new sqlite3.Database(dbPath);

// Cria a tabela se não existir
db.serialize(() => {
  db.serialize(() => {
    db.run(`
    CREATE TABLE IF NOT EXISTS devices (
      id TEXT PRIMARY KEY,
      name TEXT,
      registeredAt TEXT,
      lastSeen TEXT,
      status TEXT,
      commands TEXT
    )
  `);

    db.run(`
    CREATE TABLE IF NOT EXISTS sensor_data (
      id INTEGER PRIMARY KEY AUTOINCREMENT,
      deviceId TEXT,
      temperature REAL,
      humidity REAL,
      timestamp TEXT
    )
  `);
  });
});

export default db;
