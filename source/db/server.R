library(RNeo4j)
library(shiny)
library(shinyjs)

graph = startGraph("http://107.170.75.7:7474/db/data/",
									 username = "neo4j",
									 password = "meeseek")
useShinyjs()

function(input, output, session) {
	# REGISTER
	
	observe({
		if (is.null(input$new_user) || input$new_user == "") {
			shinyjs::disable("registerButton")
		} else {
			shinyjs::enable("registerButton")
		}
	})
	
	
	observeEvent(input$registerButton, {
		disable(input$new_user)
		newNode = createNode(graph,
												 "User",
												 name = input$new_user,
												 password = input$new_pass)
	})
	
	
	# LOGIN
	
	observe({
		if (is.null(input$my_user) || input$my_user == "") {
			shinyjs::disable("loginButton")
		} else {
			shinyjs::enable("loginButton")
		}
	})
	
	
	observeEvent(input$loginButton, {
		if (input$my_user == userCheck) {
			shinyjs::alert("Success!")
		} else {
			shinyjs::alert("Username and password are incorrect.")
		}
		
	})
}