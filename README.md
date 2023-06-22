# Proiect OOP - Sistem de gestiune al unui local pentru evenimente

## Tema 2

#### Cerințe
- [X] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp`
- [X] moșteniri
  - [X] clasă cu atribut de tip pointer la o clasă de bază cu derivate
  - [X] funcții virtuale (pure) apelate prin pointeri de bază din clasa de mai sus, constructori virtuali (clone)
    - minim o funcție virtuală va fi **specifică temei** (e.g. nu simple citiri/afișări)
  - [X] apelarea constructorului din clasa de bază din constructori din derivate
  - [X] smart pointers
  - [X] `dynamic_cast`
- [X] suprascris cc/op= pentru copieri/atribuiri corecte, copy and swap
- [X] excepții
  - [X] ierarhie proprie cu baza `std::exception` sau derivată din `std::exception`; minim 2 clase pentru erori specifice
  - [X] utilizare cu sens: de exemplu, `throw` în constructor, `try`/`catch` în `main`
- [X] funcții și atribute `static`
- [X] STL
- [X] cât mai multe `const`
- [X] la sfârșit: commit separat cu adăugarea unei noi derivate fără a modifica restul codului
- [X] tag de `git`: de exemplu `v0.2`

## Tema 3

#### Cerințe
- [X] 2 șabloane de proiectare (design patterns, da, factory (pentru felurile de mâncare și la angajați), singleton în Manager și object pool pentru săli)
- [ ] o funcție șablon (template) cu sens; minim 2 instanțieri
- [ ] o clasă șablon cu sens; minim 2 instanțieri
<!-- - [ ] o specializare pe funcție/clasă șablon -->
- [ ] tag de `git`: de exemplu `v0.3` sau `v1.0`

## Resurse

- adăugați trimiteri către resursele externe care v-au ajutat sau pe care le-ați folosit
