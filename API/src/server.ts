import express from "express";
import cors from "cors";
import deviceRoutes from "./routes/deviceRoutes";

const app = express();
const PORT = 3000;

app.use(cors());
app.use(express.json());

app.use("/device", deviceRoutes);

app.listen(PORT, () => {
  console.log(`API running at http://localhost:${PORT}`);
});

export default app;
