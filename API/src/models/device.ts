export interface Device {
  id: string; // Identificador único do dispositivo IoT
  name?: string; // Nome mnemônico do dispositivo (Opcional)
  registeredAt: Date; // Quando que ele fez a inscrição
  lastSeen: Date; // Ultima vez que houve uma comunicação
  status?: string; // Status (Opcional)
  commands?: string[]; // Comandos pendentes
}
