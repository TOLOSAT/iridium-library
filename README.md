# TOLOSAT Iridium Library

This library contains the Iridium 9603 modem driver and the associated PUS 193 service used by the flight software. The driver is based on *ISU AT Command Reference, MAN0009, version 5, 25 August 2014*.

## Layout

- `include/drivers/iridium9603.h` exports the modem driver API;
- `include/service/pus193.h` exports the service API;
- `components/drivers/` contains the driver implementation and private AT command definitions;
- `components/service/` contains the PUS 193 implementation.

From the parent flight-software repository:

```bash
make iridium
make iridium-verif
make iridium-clean
```

The archive is written to `build/libs/libiridium.a`.

## Configuration

Library options belong in `gen/Kconfig.options`. The parent project sources this fragment and generates a library-scoped `autoconf.h`; the fragment is currently empty. A standalone checkout can maintain its own configuration with `make default_defconfig` and `make menuconfig`. Initialise the `tools/` submodule recursively before generating or building from a standalone checkout.

## Acronyms

| Acronym | Definition |
|---------|------------|
| DTE | Data Terminal Equipment, here the on-board computer. |
| DTR | Data Terminal Ready, the physical readiness signal from the DTE. |
| ISU | Iridium Subscriber Unit. |
| MO | Mobile Originated, satellite-to-ground transmission. |
| MT | Mobile Terminated, ground-to-satellite reception. |

## License

This library is licensed under the Apache License 2.0. See [`LICENSE`](LICENSE)
for details.
