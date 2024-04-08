library(glue)

amountCode <- 3
amountRuns <- 2

par(mfrow = c(1, 3))
plotfunction <- function(language) {
	output_list <- list()
	for (x in 1:amountRuns) {
		output <- c()
		if (language == "c") {
			output <- system(glue::glue("./matrix.out {amountCode}"), intern = TRUE)
		}
		else if (language == "python") {
			output <- system(glue::glue("python matrix.py {amountCode}"), intern = TRUE)
		}
		else if (language == "numpy") {
			output <- system(glue::glue("python matrixnumpy.py {amountCode}"), intern = TRUE)
		}
		output <- as.numeric(output)
		output_list[[x]] <- output
	}
	result <- output_list[[1]]
	for (x in 2:amountRuns) {
		result <- result + output_list[[x]]
	}
	plot(result, type = 'l')
	legend(x = "topright", legend = language)
	return(result)
}

ctime <- plotfunction("c")
pythontime <- plotfunction("python")
numpytime <- plotfunction("numpy")
