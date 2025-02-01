# keeloq manufacturer code extractor
That test tries to find the manufacturer code used to make keeloq key by serial for normal learn method. processes change the 64bit manufacturer code step by step and check the generated key to find the manufacture code. so it takes a long time ...

See [keeloq key generator from manufacturer code](https://github.com/ioelectro/hcs-programmer-soft) or [KeeLoq library](https://github.com/liyanboy74/KeeLoq) for more information.

run by github action:

edit `Makefile` and add the `SER` and `KEY(32bit HSB)`.

or run local:
```
make
./mfcode [SER] [KEY(32bit HSB)] 
```
*Example:* `./mfcode A9C2E0E1 CFD85AA5`

but you need a supercomputer! ;)

in Actions can be see that trying 3161551615 (HEX: BC7472FF) times take 6h time.<br>
for full 64bit it need 3996378 years! :)



