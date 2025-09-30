#Chapter 3 and 4 notes

## Chapter 3

### Device Naming in CP/M:

* CP/M uses logical names for devices, which are easier to refer to than full physical names (e.g., "CRT:" for the operator's console).
* Logical device names you’ll use:
    * CON: (Console, usually your CRT terminal)
    * LST: (List device, usually your line printer)
    * RDR: (Reader device, e.g., card or tape reader)
    * PUN: (Punch device, e.g., tape punch or modem)

### Disk Drives:

* Physical drives are numbered (0, 1, etc.).
* Logical names for drives are A:, B:, etc., and these map directly to the physical drives in a simple system.

### I/O Device Selection:

* CP/M lets you select which physical device acts as each logical device using the IOBYT memory byte (not actual switches).
* For example, RDR: could be a card reader, tape reader, or modem—in software you change which device is used.
* Normally, you won't need to change these settings for the exercises.

### Logical vs. Physical Devices:

* Logical names (like CON:) refer to device roles in the operating system.
* Physical devices (like CRT terminal or line printer) are the actual hardware.
* The operator’s console is the CRT:, which acts as logical device CON:.
* The line printer is LPT:, acting as logical device LST:.

### Flexibility and Defaults:

* Devices are usually permanently connected; software controls which device is active.
* In the exercises, you usually use CRT: as CON: and LPT: as LST:.





## Chapter 4
