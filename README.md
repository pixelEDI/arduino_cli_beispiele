# arduino-cli Beispiele
Arduino CLI ist ein wichtiges Werkzeug für die Integration von Arduino-Projekten in CI/CD-Pipelines, 
da es eine einfache und skriptbare Möglichkeit bietet, Arduino-Sketches zu kompilieren und hochzuladen. 
Mit Arduino CLI kannst du automatisierte Builds und Tests durchführen, was die kontinuierliche Integration 
und Bereitstellung von Firmware für Arduino-Projekte erheblich erleichtert. Es ermöglicht dir, Arduino-Entwicklungsprozesse 
zu automatisieren, Fehler frühzeitig zu erkennen und konsistente Builds zu gewährleisten, ohne manuelle Eingriffe. 
Ideal für die Automatisierung und Verbesserung des Entwicklungsworkflows in CI/CD-Systemen.

## Beispiele
Das Video dazu: https://youtube.com/@pixeledi

### config
- https://arduino.github.io/arduino-cli/1.0/configuration/

`arduino-cli config init`

Findet man unter `/home/{deinuser}/.arduino15/arduino-cli.yaml`

### Arduino Uno R4 Sketch

1. Erstelle ein neues Sketch-Projekt:
    ```bash
    arduino-cli sketch new 1_ArduinoUnoR4_blink
    ```

2. Wechsle in das Projektverzeichnis:
    ```bash
    cd 1_ArduinoUnoR4_blink
    ```

3. Aktualisiere den Index 
    ```bash
    arduino-cli core update-index
    ```

4. Zeige eine Liste der angeschlossenen Boards an:
    ```bash
    arduino-cli board list
    arduino-cli board listall
    ```

5. Zeige eine Liste der verfügbaren Kernels an und installiere:
    ```bash
    arduino-cli core list
    arduino-cli core install arduino:renesas_uno 
    ```

6. Kompiliere das Projekt:
    ```bash
    arduino-cli compile --fqbn arduino:renesas_uno:unor4wifi 1_ArduinoUnoR4_blink
    ```

7. Lade das Projekt auf das Board hoch:
    ```bash
    arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:renesas_uno:unor4wifi 1_ArduinoUnoR4_blink
    ```


### Mit Libraries

1. Suche nach der Library:
    ```bash
    arduino-cli lib search ArduinoGra
    ```

2. Installiere die Library:
    ```bash
    arduino-cli lib install ArduinoGraphics
    ```


## ESP32
ESP32 Board installieren
```bash
arduino-cli core update-index
arduino-cli core install esp32:esp32
```
FQBN 
```bash
esp32:esp32:XIAO_ESP32C3
```

## Links
- Doku: https://arduino.github.io/arduino-cli/1.0/
- Installation: https://arduino.github.io/arduino-cli/1.0/installation/
- Anwendung: https://arduino.github.io/arduino-cli/1.0/getting-started/
