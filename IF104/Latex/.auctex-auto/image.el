(TeX-add-style-hook
 "image"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("report" "a4paper")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("geometry" "top=2cm" "bottom=2cm" "left=2cm" "right=2cm") ("inputenc" "utf8") ("babel" "french") ("hyperref" "colorlinks")))
   (TeX-run-style-hooks
    "latex2e"
    "report"
    "rep10"
    "graphicx"
    "geometry"
    "inputenc"
    "babel"
    "amsmath"
    "amssymb"
    "hyperref"
    "multicol"
    "fancyhdr")
   (LaTeX-add-labels
    "figure 1"))
 :latex)

