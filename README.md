A kód egy amóba játékot indít el gép ellen. Ez az első kisebb projektem, használtam hozzá internetes segítséget, de csak rávezetésképpen.

Futtatás
1. Töltsük le az alábbi oldalról a mingw/gcc compilert. https://winlibs.com/#download-release
2. Csomagoljuk ki arra a drive-ra ahol a rendszer is található.
3. Adjuk hozzá a mingw64\bin elérési útvonalát a rendszer környezeti változóihoz.
4. Töltsük le a main.c filet a repositoryból, majd nyissuk meg az elérési útvonalát.
5. Indítsuk el a file-ban a command promptot, majd írjuk be a következőt: "gcc main.c"
6. Ezután írjuk be, hogy ".\a.exe".

A program
1. A játékot az X jelű játékos kezdi.
2. A kód megkérdezi, hogy melyik sorba szeretnénk lépni 1-3-ig. Beírjuk a számot, aztán leenterezzük.
3. Ezután megkérdezi melyik oszlopba szeretnénk lépni. Beírjuk 1-3-ig a számot, majd enter.
4. Ezután a gép lép, ami teljesen randomizáltan dől el az üres mezők alapján.
5. Mindaddig megy a játék, amíg nem születik egy nyertes, vagy döntetlen lesz az állás.
6. A játék befejeztével a kód megkérdezi, hogy akarunk-e még játszani, ezt egy "Y"-Igen vagy "N"-Nem karakter beírásával tehetjük meg.
7. Ha "Y"-t írunk, a játék újraindul, ha "N"-t akkor a kód bezárja saját magát.
