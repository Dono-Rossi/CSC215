# Chapter 2


#### Firmware Monitor
- Because turning off a computer wipes its RAM, and waking computers initially read location 0 (which is RAM):
    - A bootup ciruit is activated which masks the RAM and substitutes it with a "shadow PROM" which is executed and then disonnected.
- The firmware monitor is a built-in, low-level control program residing in ROM.
- It provides basic input/output (I/O) operations, diagnostic routines, and system initialization.
- The monitor acts as an interface between the hardware and higher-level software like the operating system.
- Allow basic hardware interaction, such as reading from keyboard, displaying text, and accessing disk drives.

#### Operating System (CP/M)

- CP/M is loaded into RAM during system startup, typically after the monitor initializes the hardware.
- The OS handles file management, program execution, memory allocation, and device control.
- CP/M consists of system modules such as the Basic Input Output System (BIOS) and Basic Disk Operating System (BDOS).

#### Customizing CP/M

- CP/M can be customized to suit specific hardware configurations and user requirements.
- The BIOS portion of CP/M is designed for customization; it contains routines for hardware-specific operations.
- System integrators modify the BIOS to support unique disk formats, I/O devices, or terminal types.
- Customization allows CP/M to be portable across various computer systems with minimal changes to the core OS.

#### Application Programs

- Application programs are user-written or commercially available software that run under CP/M.
- They use system calls (standardized interfaces) to interact with CP/M for file I/O, memory management, and device access.
- Examples include word processors, assemblers, and database managers.
- Application programs rely on the OS for resources and do not directly access hardware.

#### Special Memory Areas

- CP/M systems reserve specific memory regions for system use:
    - Transient Program Area (TPA): Main area where user programs are loaded and executed; starts at address 0100H.
    - System Reserved Area: Includes interrupt vectors, BIOS, BDOS, and other control structures.
    - BDOS and BIOS: Loaded at fixed locations near the top of memory.
Memory organization ensures that user programs and system components do not conflict.
- Application programs must avoid overwriting reserved areas to function correctly.

#### Summary of Relationships

- The firmware monitor initializes the system and provides minimal I/O.
- The operating system (CP/M) is loaded after firmware, managing hardware and providing standardized services.
- Customization of CP/M (mainly the BIOS) enables compatibility with different hardware.
- Application programs utilize OS services to perform tasks.
- Special memory areas protect system integrity and organize program execution.

### Key Definitions:

- Firmware Monitor: ROM-resident program for initial hardware control.
- Operating System (CP/M): RAM-based software for resource management and services.
- BIOS: Customizable hardware-specific routines within CP/M.
- BDOS: Core disk and file management routines in CP/M.
- TPA: Main memory region for running user programs.

