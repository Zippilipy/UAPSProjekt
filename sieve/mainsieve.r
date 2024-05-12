library(glue)

amountCode <- 100
amountRuns <- 100
pdf("sieve.pdf", width = 20, height = 11)

par(mfrow = c(1, 3))
plotfunction <- function(language) {
	output_list <- list()
	for (x in 1:amountRuns) {
		output <- c()
		if (language == "c") {
			output <- system(glue::glue("./sieve/sieve.out {amountCode}"), intern = TRUE)
		}
		else if (language == "python") {
			output <- system(glue::glue("python sieve/sieve.py {amountCode}"), intern = TRUE)
		}
		else if (language == "numpy") {
			output <- system(glue::glue("python sieve/sievenumpy.py {amountCode}"), intern = TRUE)
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
write.table(ctime, file = "csieve.txt", col.names = FALSE)
write.table(pythontime, file = "pythonsieve.txt", col.names = FALSE)
write.table(numpytime, file = "numpysieve.txt", col.names = FALSE)
