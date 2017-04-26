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
			shinyjs::disable("registerButton") # Disable button to disallow null data / errors
		} else {
			shinyjs::enable("registerButton")
		}
	})
	
	# Create node (the user's account) when the button is clicked.
	observeEvent(input$registerButton, {
		disable(input$new_user)
		newNode = createNode(graph,
												 "User",
												 username = input$new_user,
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
		# Create a temp node to compare to existing accounts.
		
		verificationNode = createNode(graph,
																	"User",
																	username = input$my_user,
																	password = input$my_pass) # User's login attempt
		
		query =  "MATCH (n:User {username:{username}})
		RETURN n"
		
		comparisonNode = getSingleNode(graph, query, username = input$my_user) # Retrieving actual account info
		
		# Compare the login attempt info to the actual info.
		# If they match, the attempt is successful.
		
		if (toString(verificationNode) == toString(comparisonNode)) {
			showNotification("Success!", duration = 5, closeButton = TRUE, type = "message")
			delete(verificationNode) # Redundant node
		} else {
			showNotification("Username and password are incorrect.", 
											 duration = 5, closeButton = TRUE, type = "error")
			delete(verificationNode) # Redundant node
		}
		
	})
}