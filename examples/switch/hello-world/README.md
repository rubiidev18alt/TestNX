# Nintendo Switch Hello World Homebrew

This is a minimal Nintendo Switch homebrew app based on the public-domain
`graphics/printing/hello-world` example from the
[`switchbrew/switch-examples`](https://github.com/switchbrew/switch-examples)
repository.

## What it does

- Initializes the libnx console.
- Prints `Hello World!` near the middle of the screen.
- Polls controller input once per frame.
- Exits back to hbmenu when the `+` button is pressed.

## Build requirements

Install the devkitPro Switch toolchain (`devkitA64`, `libnx`, and
`switch-tools`) and set `DEVKITPRO` in your environment.

```sh
cd examples/switch/hello-world
make
```

The build produces a `.nro` homebrew executable when the devkitPro toolchain is
available.
