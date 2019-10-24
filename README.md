# bs-execa

[BuckleScript](https://bucklescript.github.io) bindings for [execa](https://github.com/sindresorhus/execa).

# Usage

```reasonml
Execa.commandSync("my command line")
```

# Developers section

First and formost, configure your environment with `npm install`.

Specific BuckleScript aliases (`clean`, `build`, `watch`, `test`...) are defined
in the `package.json` file to be used with `npm run [alias]`.
