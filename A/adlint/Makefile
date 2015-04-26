MAKEINFO = makeinfo

.SUFFIXES : .texi .html .txt

.texi.html :
	$(MAKEINFO) --html --no-split --css-include=texinfo.css -o $@ $<

.texi.txt :
	$(MAKEINFO) --plaintext -o $@ $<

TARGET = users_guide_ja.html users_guide_en.html developers_guide_ja.html

all : $(TARGET)

clean :
	rm -f $(TARGET)
