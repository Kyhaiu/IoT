import { Request, Response } from "express";
import * as deviceService from "../services/deviceService";

export const register = (req: Request, res: Response) => {
  const { id, name } = req.body;

  console.log(id, name);

  if (!id) return res.status(400).json({ error: "Device ID required" });

  const device = deviceService.registerDevice(id, name);
  res.json({ message: "Registered", device });
};

export const sendData = (req: Request, res: Response) => {
  const { id, data } = req.body;
  console.log(`Data from ${id}:`, data);
  res.json({ message: "Data received" });
};

export const getCommands = (req: Request, res: Response) => {
  const { id } = req.params;

  if (!id) return res.status(400).json({ error: "Device ID required" });

  const commands = deviceService.fetchCommands(id);
  res.json({ commands });
};
