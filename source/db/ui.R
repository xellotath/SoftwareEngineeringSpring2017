library(RNeo4j)
library(shiny)
library(shinyjs)
library(shinythemes)

# Accessed at https://meeseeks.shinyapps.io/database/

# Connect to the Neo4j DB.
graph = startGraph("http://107.170.75.7:7474/db/data/",
                   username = "neo4j",
                   password = "meeseek")

fluidPage(
  theme = shinytheme("yeti"),
  titlePanel("Team Mr. Meeseeks"),
  tagList(
    useShinyjs(),
    navbarPage(
      "Account",
      fluid = TRUE,
      tabPanel(
        "Register",
        fluidRow(column(6, wellPanel(
          textInput("new_user", "Username: ", "")
        ))),
        
        fluidRow(column(6, wellPanel(
          passwordInput("new_pass", "Password: ", "")
        ))),
        
        fluidRow(column(4, wellPanel(
          actionButton("registerButton", "Register", icon = NULL , width = "100%")
        )))
      ),
      tabPanel(
        "Login",
        fluidRow(column(6, wellPanel(
          textInput("my_user", "Username: ", "")
        ))),
        
        fluidRow(column(6, wellPanel(
          passwordInput("my_pass", "Password: ", "")
        ))),
        
        fluidRow(column(4, wellPanel(
          actionButton("loginButton", "Login", icon = NULL , width = "100%")
        )))
      )
    )
  )
)
