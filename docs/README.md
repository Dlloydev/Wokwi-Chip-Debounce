# Wokwi Debounce Chip

This custom chip for [Wokwi](https://wokwi.com/) cleans the transitions of a noisy digital signal.

- Duration: 100-5000 microseconds

## Pin names

| Name | Description                            |
| ---- | -------------------------------------- |
| IN   | Signal Input                           |
| OUT  | Debounced and Deglitched Signal Output |

## Usage

To use this chip in your project, include it as a dependency in your `diagram.json` file:

```json
  "dependencies": {
    "chip-debounce": "github:Dlloydev/Wokwi-Chip-Debounce@1.0.2"
  }
```

Then, add the chip to your circuit by adding a `chip-debounce` item to the `parts` section of `diagram.json`:

```json
  "parts": {
    ...,
    { "type": "chip-debounce", "id": "debounce1" }
  },
```

For a complete example, see [the inverter chip test project](https://wokwi.com/projects/350946636543820370).

