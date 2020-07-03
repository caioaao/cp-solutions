#!/usr/bin/env bash
COMPILER_VERSION='4.02.1'
SWITCH_NAME="${COMPILER_VERSION}-codeforces"

opam switch create "${SWITCH_NAME}" "${COMPILER_VERSION}"
# opam pin --switch="${SWITCH_NAME}" add ocaml-lsp-server https://github.com/ocaml/ocaml-lsp.git#45ac7ee6ddebcf2e4e2d0e8e18347e2143618bb8
opam install --switch="${SWITCH_NAME}" num camlp4
# opam install --switch="${SWITCH_NAME}" ocaml-lsp-server
