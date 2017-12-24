# qdsa-space2017
---
This is an optimized software library of the Quotient Digital Signature Algorithm (qDSA). This library is an extension of the original code written by [Joost Renes](https://www.cs.ru.nl/~jrenes/) (v. 2017-05-24). However, our code is enhanced with the following new features:

**New Features**:

 - New right-to-left algorithm to calculate fixed-point multiplications on Montgomery curves.
 - Optimized prime field arithmetic for 64-bit Intel architectures using MULX and ADCX/ADOX instructions.
 - A short-size look-up table of 8 KB.
 - Around 25,000 signatures-per-second on an Intel Haswell processor running at 3.4 GHz ([see more details](#benchmark)).
 - Secure software protected with countermeasures against some side-channel attacks, e.g. constant-time execution, memory accessing and branching using non-secret data.  

----

## Research Resources

This software library is part of a peer-reviewed paper titled _"A Secure and Efficient Implementation of the Quotient Digital Signature Algorithm (qDSA)"_ authored by:
 * [Armando Faz-Hernández](http://www.ic.unicamp.br/~armfazh)
 * [Hayato Fujii](http://lasca.ic.unicamp.br/~hayato/)
 * [Diego Aranha](https://sites.google.com/site/dfaranha/)
 * [Julio López](http://www.ic.unicamp.br/pessoas/docentes/jlopez)

all of them are with the [Institute of Computing](http://ic.unicamp.br) of the University of Campinas, Brazil.
This paper was presented at the Seventh International Conference on Security, Privacy, and Applied Cryptography Engineering ([SPACE 2017](http://www.space.dbcegoa.ac.in/)) conference.

To cite this work use:

```tex
@inproceedings{faz_qdsa_space2017,
    author = {Armando Faz-Hern\'{a}ndez and Hayato Fujii and Diego F. Aranha and Julio L\'{o}pez},
    address = "Cham",
	booktitle = "Security, Privacy, and Applied Cryptography Engineering: 7th International Conference, SPACE 2017, Goa, India, December 13-17, 2017, Proceedings",
	doi = "10.1007/978-3-319-71501-8_10",
	editor = "Ali, Sk Subidh and Danger, Jean-Luc and Eisenbarth, Thomas",
	isbn = "978-3-319-71501-8",
	pages = "170–189",
	publisher = "Springer International Publishing",
	title = "A Secure and Efficient Implementation of the Quotient Digital Signature Algorithm (qDSA)",
	url = "https://doi.org/10.1007/978-3-319-71501-8_10",
	year = "2017"
}

```

----

## Compilation Steps:

#### Pre-requirements

- A C-language compiler, e.g. gcc, clang, or icc.
- The CMake tool.
- Make command.


#### Compilation
You can use `make` command as follows:

```
 $ cd qdsa-space2017
 $ CC=gcc make 
```

If compilation succeds, four executable files will be generated:

 - ```qdsa_ref```: The reference implementation of qDSA.
 - ```qdsa_x64```: The reference implementation of qDSA using 64-bit optimized arithmetic.
 - ```qdsa_r2l_ref```: The reference implementation of qDSA using the new right-to-left method of point multiplication.
 - ```qdsa_r2l_x64```: The *optimized* implementation.

Alternatively, you can use the `CMake` tool to generate the same files:

```
 $ cd qdsa-space2017
 $ mkdir build
 $ cd build 
 $ CC=gcc cmake ..
 $ make 
```
----

## Benchmark
Performance benchmark on Intel architectures.


#### Runing benchmark
Execute this program to obtain the performance report:

```
 $ ./qdsa_r2l_x64
```

#### Timings
These are timings (reported in 10³ clock cycles) measured on Haswell and Skylake Intel processors of the optimized library (`qdsa-r2l-x64`).

| Operation | Haswell | Skylake |
| :------ | ------: | ------: |
| KeyGen | 103.8 | 86.8 |
| Signature | 130.1 | 114.6 |
| Verification | 309.6 | 253.5 |

#### Comparison
Performance rendered on a Haswell processor running at 3.4 GHz.

| Scheme | Sign/second | Verification/second |
| :------ | ------: | ------: |
| ECDSA (P-256) | 25.3 | 10.2 |
| Ed25519 | 48.7 | 17.1 |
| qDSA | 25.1 | 12.1 |


----

### License 
GNU Lesser General Public License v3.0 ([LICENSE](https://www.gnu.org/licenses/lgpl-3.0.txt))

----

### Contact 

To report some issues or comments of this project, please use the [issues](https://github.com/armfazh/qdsa-space2017/issues) webpage. 


----
