# group_x

## Sovelluksen asennus

- Luo tietokanta ajamalla tiedosto db_dump.sql ja sqlcode.txt
- Luo backend kansioon tiedosto .env, jonka mallina voit käyttää tiedostoa .env_example
- Anna backend kansiossa komento **npm install**
- käynnistä backend sovellus komennolla node app.js

## Qt sovelluksen style-tiedosto

Tiedoston style.qss avulla voit muokata eri kontrollerien (buttonit, line-edit jne) ulkoasua. Siinä on malliksi muokattu button-tyyli.

### style-tiedoston käyttö

Jos haluat käyttää style tiedostoa omassa sovelluksessa sinun tulee luoda style.qss tiedoston lisäksi resource-tiedosto ja muokata main.cpp ja lisätä CMakeLists.txt tiedostoon rivit:

 ```
qt_add_resources(RESOURCES_ADDED resource.qrc)
target_sources(bank-automat PRIVATE ${RESOURCES_ADDED})
 ```

Tässä esimerkissä tuon resource.qrc tiedoston sisätö on seuraava:
 ```
<RCC>
    <qresource prefix="/">
        <file>style.qss</file>
    </qresource>
</RCC>
 ```
Ja style.qss tiedostoon voi sitten lisätä tyylejä kuten tässä esimerkissä:
 ```
QPushButton{
    background-color:lightblue;
    border: 2px solid gray;
    border-radius:10px;
}
 ```

