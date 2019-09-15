# Atoms

[Atoms](https://web.archive.org/web/20110315180828if_/http://msdn.microsoft.com/en-us/library/ms649053%28v=VS.85%29.aspx) are exists in Windows at least from Win95. There are two tables of atoms:

* Global (system-wide)
* Local (application-based)

Atom table is a hash map of strings. So, we may iterate and grab those strings from both stores to show hidden live of operation system.

### Compiling

Use [Dev-Cpp](https://sf.net/p/orwelldevcpp). Or gcc+mingw (parameters are in \*.dev files).
