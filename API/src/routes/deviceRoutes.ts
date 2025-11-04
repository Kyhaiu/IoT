import { Router } from "express";
import * as deviceController from "../controllers/deviceController";

const router = Router();

// Rota de teste
router.get("/test", (req, res) => {
  res.status(200).json({ message: "The server is accessible" });
});

// Registrar dispositivo
router.post("/register", deviceController.register);

// Enviar dados do dispositivo (salva no DB)
router.post("/data", deviceController.sendData);

// Buscar comandos pendentes para um dispositivo (e limpá-los)
router.get("/commands/:id", deviceController.getCommands);

// Adicionar um comando para um dispositivo (ex: via dashboard)
router.post("/commands", deviceController.addCommand);

// Listar todos os dispositivos (útil para debug / dashboard)
router.get("/devices", deviceController.listDevices);

// Listar leituras de um dispositivo (histórico)
router.get("/data/:id", deviceController.getDeviceData);

export default router;
