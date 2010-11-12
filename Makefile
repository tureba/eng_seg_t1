CFLAGS=-pipe -std=c99 -O2

all: progs doc

progs: crypt decrypt

doc: relatorio.pdf

crypt: crypt.c

decrypt: decrypt.c

relatorio.pdf: relatorio.tex
	-pdflatex relatorio.tex
	-pdflatex relatorio.tex

clean:
	-rm -f crypt decrypt `ls relatorio.* 2>/dev/null | grep -v relatorio.tex`
