import { Router } from "express";
import * as deviceController from "../controllers/deviceController";

const router = Router();

router.get("/test", (req, res) => {
  res.status(200).send(JSON.stringify({ message: "The server is accessible" }));
});
router.post("/register", deviceController.register);
router.post("/data", deviceController.sendData);
router.get("/commands/:id", deviceController.getCommands);

export default router;
