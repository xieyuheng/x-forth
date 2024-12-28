# x-forth

x-forth is a [forth-like language](https://en.wikipedia.org/wiki/Forth_(programming_language))
with tagged value
that is extensible by C.

## Install

Dependencies:

- `libx11`:
  - debian: `sudo apt install libx11-dev`
  - ubuntu: `sudo apt install libx11-dev`

Compile:

```
git clone https://github.com/cicada-lang/x-forth
cd x-forth
make -j
make test
```

The compiled binary `./bin/x-forth` is the command-line program.

## Development

```shell
make all      # compile src/ files to lib/ and bin/
make run      # compile and run the command-line program
make test     # compile and run test
make clean    # clean up compiled files
```

## References

**Books**:

- [scalable c](https://github.com/booksbyus/scalable-c)

## Contributions

To make a contribution, fork this project and create a pull request.

Please read the [STYLE-GUIDE.md](STYLE-GUIDE.md) before you change the code.

Remember to add yourself to [AUTHORS](AUTHORS).
Your line belongs to you, you can write a little
introduction to yourself but not too long.

## License

[GPLv3](LICENSE)
