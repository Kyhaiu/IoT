import { Request, Response } from "express";
import * as deviceService from "../services/deviceService";

export const register = async (req: Request, res: Response) => {
  const { id, name } = req.body;

  if (!id) return res.status(400).json({ error: "Device ID required" });

  try {
    const device = await deviceService.registerDevice(id, name);
    res.status(200).json({ message: "Registered", device });
  } catch (err) {
    console.error(err);
    res.status(500).json({ error: "Internal server error" });
  }
};

export const sendData = async (req: Request, res: Response) => {
  const { id, data } = req.body;
  if (!id || !data)
    return res.status(400).json({ error: "Missing id or data" });

  console.log(`Data from ${id}:`, data);

  // Salva no banco
  deviceService.saveSensorData(id, data.temperature, data.humidity);

  res.json({ message: "Data received", received: data });
};

export const getCommands = async (req: Request, res: Response) => {
  const { id } = req.params;
  if (!id) return res.status(400).json({ error: "Device ID required" });

  try {
    const commands = await deviceService.fetchCommands(id);
    res.json({ commands });
  } catch (err) {
    console.error(err);
    res.status(500).json({ error: "Internal server error" });
  }
};

// adiciona um comando para o dispositivo (body: { id, command })
export const addCommand = async (req: Request, res: Response) => {
  const { id, command } = req.body;
  if (!id || !command)
    return res.status(400).json({ error: "Missing id or command" });
  try {
    await deviceService.addCommand(id, command);
    res.json({ message: "Command added" });
  } catch (err) {
    console.error(err);
    res.status(500).json({ error: "Internal server error" });
  }
};

// lista todos os dispositivos
export const listDevices = async (req: Request, res: Response) => {
  try {
    const devices = await deviceService.listDevices();
    res.json({ devices });
  } catch (err) {
    console.error(err);
    res.status(500).json({ error: "Internal server error" });
  }
};

// retorna leituras (sensor_data) de um dispositivo por id
export const getDeviceData = async (req: Request, res: Response) => {
  const { id } = req.params;
  if (!id) return res.status(400).json({ error: "Device ID required" });
  try {
    const rows = await deviceService.getSensorData(id);
    res.json({ data: rows });
  } catch (err) {
    console.error(err);
    res.status(500).json({ error: "Internal server error" });
  }
};
