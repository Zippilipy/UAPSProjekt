library(glue)

amountCode <- 100
amountRuns <- 100
pdf("simulations.pdf", width = 20, height = 11)
par(mfrow = c(1, 3))
plotfunction <- function(language) {
	output_list <- list()
	for (x in 1:amountRuns) {
		output <- c()
		if (language == "c") {
			output <- system(glue::glue("./simulations.out {amountCode}"), intern = TRUE)
		}
		else if (language == "python") {
			output <- system(glue::glue("python simulations.py {amountCode}"), intern = TRUE)
		}
		else if (language == "numpy") {
			output <- system(glue::glue("python simulationsnumpy.py {amountCode}"), intern = TRUE)
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
write.table(ctime, file = "csimulations.txt", col.names = FALSE)
write.table(pythontime, file = "pythonsimulations.txt", col.names = FALSE)
write.table(numpytime, file = "numpysimulations.txt", col.names = FALSE)
