all:
	pdflatex TD1.tex
	pdflatex TD1.tex
	pdflatex TD2.tex
	pdflatex TD2.tex
	pdflatex TD3.tex
	pdflatex TD3.tex
	pdflatex TD4.tex
	pdflatex TD4.tex
	pdflatex TD5.tex
	pdflatex TD5.tex
	evince TD1.pdf TD2.pdf TD3.pdf TD4.pdf TD5.pdf
	rm -f TD?.log TD?.aux TD?.pdf

TD1:
	pdflatex TD1.tex
	evince TD1.pdf
TD2:
	pdflatex TD2.tex
	evince TD2.pdf

TD3:
	pdflatex TD3.tex
	evince TD3.pdf

TD4:
	pdflatex TD4.tex
	evince TD4.pdf

TD5:
	pdflatex TD5.tex
	evince TD5.pdf

clean:
	rm -f TD?.log TD?.aux TD?.pdf
