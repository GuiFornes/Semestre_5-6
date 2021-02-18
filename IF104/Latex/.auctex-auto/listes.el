(TeX-add-style-hook
 "listes"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("report" "a4paper")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("geometry" "top=2cm" "bottom=2cm" "left=2cm" "right=2cm")))
   (TeX-run-style-hooks
    "latex2e"
    "report"
    "rep10"
    "geometry"))
 :latex)

