import express from "express";
import cors from "cors";
import deviceRoutes from "./routes/deviceRoutes";

const app = express();
const PORT = 3000;
const HOST = "0.0.0.0";

app.use(cors());
app.use(express.json());

app.use("/device", deviceRoutes);

app.listen(PORT, HOST, () => {
  console.log(`API running at http://${HOST}:${PORT}`);
});

export default app;
