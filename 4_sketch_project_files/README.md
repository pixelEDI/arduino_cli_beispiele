# arduino-cli Sketch project file

In diesem Repo geht es um die Nutzung von arduino-cli sketch project files

Zum Start in die Arduino CLI empfehle ich mein Tutorial: <https://www.youtube.com/watch?v=D8v7Frws4KA>

## Hintergrund 

> <https://docs.arduino.cc/arduino-cli/>

Ich verwende gerne die Arduino-CLI, weil die Arduino IDE schwerfällig und etwas unübersichtlich bei den Einstellungen ist. Die Arduino-CLI bietet ähnlich wie PlatformIO die Möglichkeit, sämtliche Einstellungen in einer Datei zusammenzufassen. Das hat den Vorteil, dass ihr auf einen Blick Einstellungen reproduzieren könnt und der Sketch somit mit den gleichen Einstellungen und Versionsnummern läuft.

## sketch projekt files

> Doku: <https://docs.arduino.cc/arduino-cli/library-specification/>

* Im `sketch.yaml` sind die Einstellungen des Sketches enthalten, die man normalerweise über die IDE vornimmt.
* Mit dieser YAML-Datei wird alles reproduzierbarer und weniger fehleranfällig, weil jeder die Optionen auf einen Blick sieht.
* Falls du Schwierigkeiten hast, die einzelnen Optionen in der Dokumentation zu finden, kannst du die Einstellungen in der Arduino IDE vornehmen und unter „Datei > Einstellungen“ die Compiler-Meldungen auf „Alle“ stellen.
* Beim Kompilieren bekommst du dann in der ersten Zeile sämtliche Infos angezeigt, die du anschließend in dein YAML-File übernehmen kannst.

Beispiel mit Zigbee Parametern:
```yaml

profiles:
  pixeledi:
    fqbn: esp32:esp32:XIAO_ESP32C6:PartitionScheme=zigbee,DebugLevel=verbose,EraseFlash=all,ZigbeeMode=ed
    port: /dev/ttyACM0
    platforms:
      - platform: esp32:esp32 (3.2.0)
        platform_index_url: https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

### commands

- `arduino-cli compile --profile pixeledi`
- `arduino-cli upload --profile pixeledi`
- `arduino-cli monitor -p /dev/ttyACM0 -c baudrate=115200`

Nach Library suchen: 
- `arduino-cli lib search BME280`
- oder via github repo
