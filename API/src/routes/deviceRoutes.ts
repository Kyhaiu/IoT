import { Router } from "express";
import * as deviceController from "../controllers/deviceController";

const router = Router();

router.post("/register", deviceController.register);
router.post("/data", deviceController.sendData);
router.get("/commands/:id", deviceController.getCommands);

export default router;
