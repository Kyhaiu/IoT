import { Device } from "../models/device";

const devices: Device[] = [];

export const registerDevice = (id: string, name?: string) => {
  let device = devices.find((d) => d.id === id);

  console.log(device);

  if (!device) {
    device = {
      id: id,
      name: name,
      registeredAt: new Date(),
      lastSeen: new Date(),
      commands: [],
    };

    devices.push(device);
  } else {
    device.lastSeen = new Date();
  }
  return device;
};

export const getDevice = (id: string) => devices.find((d) => d.id === id);

export const addCommand = (id: string, command: string) => {
  const device = getDevice(id);
  if (device) {
    device.commands = device.commands || [];
    device.commands.push(command);
  }
};

export const fetchCommands = (id: string) => {
  const device = getDevice(id);
  if (!device) return [];
  const cmds = device.commands || [];
  device.commands = []; // Clear commands after sending
  return cmds;
};
