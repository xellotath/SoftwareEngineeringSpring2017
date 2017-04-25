# Info.md

*Specifications of the server*

### Software

* **Operating System**: [*Ubuntu 16.04, 64-bit*](https://www.ubuntu.com/)
    * License: [Multiple](https://www.ubuntu.com/about/about-ubuntu/licensing)
* **Database System**: [*Neo4j*](https://neo4j.com) with [*RNeo4j*](https://github.com/nicolewhite/RNeo4j) (for R language compatibility)
    * License: [GPL v3](https://www.gnu.org/licenses/gpl-3.0.en.html)
* **User Interface**: [*Shiny*](https://shiny.rstudio.com/) (web framework for R language)
    * License: [GNU Affero General Public License v3](https://www.gnu.org/licenses/agpl-3.0-standalone.html)

### Running the Server and Database

1. Open the terminal and start the database: `sudo service neo4j start`
2. Start R in the terminal: `R`
3. Get Shiny library: `library(shiny)`
4. Run the Shiny files: `runApp("/home/redd/Code/SoftwareEngineeringSpring2017/source/db")`