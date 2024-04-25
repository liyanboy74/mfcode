# keeloq manufacturer code extractor
that test try to find the manufactor code used to make keeloq key by serial for normal learn method. that processes change the 64bit manufactor code step by step and check the generated key for find the manufacture code. so it need a long time ...


run by github action:

edit `Makefile` and add the `SER` and `KEY(32bit LSB)`.

or run local:
```
make
./mfcode [SER] [KEY(32bit LSB)] 
```
*Example:* `./mfcode DFFACD26 5143BDD8`

but you need a supercomputer! ;)



