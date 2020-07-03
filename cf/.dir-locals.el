;;; Directory Local Variables
;;; For more information see (info "(emacs) Directory Variables")

((tuareg-mode
  (lsp-ocaml-lang-server-command "opam" "exec" "--switch=4.02.1-codeforces" "ocaml-language-server" "--stdio")
  (lsp-ocaml-lsp-server-command "opam" "exec" "--switch=4.02.1-codeforces" "ocamllsp")
  (compile-command . "opam exec --switch=4.02.1-codeforces -- ocamlfind ocamlopt nums.cmxa str.cmxa -pp camlp4o -unsafe sol.ml -o sol.exe-ocaml && ./sol.exe-ocaml < in.txt | tee out.txt")))
