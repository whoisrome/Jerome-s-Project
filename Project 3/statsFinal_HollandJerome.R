# CSCI 360 Final Exam Part 2
# Jerome Holland Jr
# Date: December 6, 2025
# Assignment: Final Exam Part 2 - Take-Home Programming Exam

# Set working directory and load datasets
setwd("C:\\Users\\ronie\\Documents\\CSCI 360")
social_media_data <- read.csv("social_media.csv")
FitnessData <- read.csv("FitnessData.csv")
halloween_data <- read.csv("halloween.csv")


# Question 1a:
# Calculate the cumulative probability up to 12 and subtract the cumulative probability up to 8.
prob_1a <- punif(12, min = 5, max = 15) - punif(8, min = 5, max = 15)
# Interpretation 1a: The probability that a walk will take between 8 and 12 minutes is 0.40.
prob_1a


# Question 1b: Time by which 90% of walks will take MORE than that time
# This asks for the 10th percentile (P(X > t) = 0.90 is equivalent to P(X <= t) = 0.10).
time_1b <- qunif(0.10, min = 5, max = 15)
# Interpretation 1b: The time by which 90% of the walks will take more than that time is 6.0 minutes.
time_1b

# Question 1c: Time by which 50% of walks will take LESS than or equal to that time --- [cite: 4, 8]
# This asks for the 50th percentile (the median).
time_1c <- qunif(0.50, min = 5, max = 15)
# Interpretation 1c: The time by which 50% of the walks will take less than or equal to that time is 10.0 minutes.
time_1c

# Average
mu_2 <- 60
# Standard Deviation
sd_2 <- 8

# Question 2a:
# For a continuous distribution, the probability of a single exact value is 0.
prob_2a <- 0
# Interpretation 2a: The probability that a randomly selected student will complete the quiz in exactly 40 minutes is 0.
prob_2a

# Question 2b:
# 60 is the mean, so P(X <= 60) is 0.50.
prob_2b <- pnorm(60, mean = mu_2, sd = sd_2)
# Interpretation 2b: The probability that a student will complete the quiz in 60 minutes or less is 0.50.
prob_2b

# Question 2c:
prob_2c <- 1 - pnorm(54, mean = mu_2, sd = sd_2)
# Interpretation 2c: The probability that a student will complete the quiz in 54 minutes or more is approximately 0.7734.
prob_2c

# Question 2d: 
prob_2d <- pnorm(68, mean = mu_2, sd = sd_2) - pnorm(48, mean = mu_2, sd = sd_2)
# Interpretation 2d: The probability that a student will complete the quiz in between 48 and 68 minutes is approximately 0.7745.
prob_2d

# Question 2e: 
prob_2e <- (1 - pnorm(72, mean = mu_2, sd = sd_2)) + pnorm(45, mean = mu_2, sd = sd_2)
# Interpretation 2e: The probability that a student will complete the quiz in more than 72 minutes OR less than 45 minutes is approximately 0.0987.
prob_2e

# Question 2f: Find the 90th percentile
time_2f <- qnorm(0.90, mean = mu_2, sd = sd_2)
# Interpretation 2f: The completion time corresponding to the 90th percentile is approximately 70.25 minutes.
time_2f

# rate
rate_3 <- 1/2 # lambda = 1/mu = 1/2

# Question 3a: 
prob_3a <- 1 - pexp(3, rate = rate_3)
# Interpretation 3a: The probability that the platform's next post will take place in more than 3 seconds is approximately 0.2231.
prob_3a

# Question 3b: 
# Mutually exclusive, so P(A OR B) = P(A) + P(B).
prob_3b <- pexp(4, rate = rate_3) + (1 - pexp(5, rate = rate_3))
# Interpretation 3b: The probability that the platform's next post will take place in less than 4 seconds or more than 5 seconds is approximately 0.9324.
prob_3b


# Question 4a: 
# H0: mu = 4
# Ha: mu > 4
# significance = 1 - 0.95 = 0.05
t_test_4a <- t.test(social_media_data$Avg_Daily_Usage_Hours, 
                     mu = 4, 
                     alternative = "greater", 
                     conf.level = 0.95)
t_test_4a
# Interpretation 4a: If the p-value is less than 0.05, reject H0. We conclude that the mean daily social media usage is significantly greater than 4 hours.

# Question 4b: 
# H0: Distribution is uniform (p = 1/7 for each platform)
# Ha: Distribution is not uniform
# significance = 1 - 0.95 = 0.05

observed_counts_4b <- table(social_media_data$Most_Used_Platform) 
observed_counts_4b
platforms_to_test <- c("Instagram", "TikTok", "YouTube", "Twitter", "Facebook", "LinkedIn", "Snapchat")
social_media_data$Platform_Factor <- factor(
  social_media_data$Most_Used_Platform, 
  levels = platforms_to_test
)
observed_counts_4b <- table(social_media_data$Platform_Factor)
observed_counts_4b
expected_probs_4b <- rep(1/7, length(observed_counts_4b))
chi_sq_4b <- chisq.test(observed_counts_4b, p = expected_probs_4b)
chi_sq_4b
# Interpretation 4b: If the p-value is less than 0.05, reject H0. We conclude that the observed distribution of most-used platforms is significantly different from a uniform distribution.

# Question 4c: 
# H0: Academic_Level and Affects_Academic_Performance are independent.
# Ha: Academic_Level and Affects_Academic_Performance are dependent (associated).
# significance = 1 - 0.95 = 0.05

contingency_table_4c <- table(social_media_data$Academic_Level, social_media_data$Affects_Academic_Performance)
contingency_table_4c
chi_sq_4c <- chisq.test(contingency_table_4c)
chi_sq_4c
# Interpretation 4c: If the p-value is less than 0.05, reject H0. We conclude there is a significant association between a student's academic level and their belief about social media affecting academic performance.


# Question 5a: 
# H0: mu = 38, Ha: mu > 38 (Right-tailed)
# signigicance = 1 - 0.90 = 0.10

t_test_5a <- t.test(FitnessData$VO2_max, mu = 38, alternative = "greater", conf.level = 0.90)
t_test_5a
# Interpretation 5a: If the p-value is less than 0.10, reject H0. We conclude the average VO2_max is significantly greater than 38.

# Question 5b: 
# H0: mu = 40, Ha: mu < 40 (Left-tailed)
# significsnce = 1 - 0.99 = 0.01
t_test_5b <- t.test(FitnessData$VO2_max, mu = 40, alternative = "less", conf.level = 0.99)
t_test_5b
# Interpretation 5b: If the p-value is less than 0.01, reject H0. We conclude the average VO2_max is significantly less than 40.

# Question 5c:
# H0: mu = 45, Ha: mu != 45 (Two-tailed)
# significance = 1 - 0.92 = 0.08
t_test_5c <- t.test(FitnessData$VO2_max, mu = 45, alternative = "two.sided", conf.level = 0.92)
t_test_5c
# Interpretation 5c: If the p-value is less than 0.08, reject H0. We conclude the average VO2_max is significantly different from 45.

# Question 5d: 
# H0: Smoking and Strength Training are independent.
# Ha: Smoking and Strength Training are dependent.
# significance typically 0.05
contingency_table_5d <- table(FitnessData$Smoker, FitnessData$Strength_Training)
contingency_table_5d
chi_sq_5d <- chisq.test(contingency_table_5d)
chi_sq_5d
# Interpretation 5d: If the p-value is less than 0.05, reject H0. We conclude there is a significant association between whether an individual smokes and whether they participate in regular strength training.


# Question 6a: 
# H0: mu = 4, Ha: mu > 4 (Right-tailed)
# significance  = 1 - 0.92 = 0.08
t_test_6a <- t.test(halloween_data$Snickers, mu = 4, alternative = "greater", conf.level = 0.92)
t_test_6a
# Interpretation 6a: If the p-value is less than 0.08, reject H0. We conclude the average score for Snickers is significantly greater than 4.

# Question 6b: 
# H0: mu_chocolate = mu_no_chocolate, Ha: mu_chocolate != mu_no_chocolate (Two-tailed)
# signifiicance = 1 - 0.95 = 0.05
print("-------------------- 6b. M&M's Score Difference --------------------")
# t_test_6b <- t.test(M.M.s ~ Preference..Chocolate, data = halloween_data)
# print(t_test_6b)
t_test_6b <- t.test(halloween_data$MMs, alternative = "two.sided", conf.level = 0.95)
t_test_6b
# Interpretation 6b: If the p-value is less than 0.05, reject H0. We conclude there is a significant difference in the average score for M&M's between the two groups.

# Question 6c: 
# H0: Classification and Preference: Chocolate are independent.
# Ha: Classification and Preference: Chocolate are dependent (associated).
# significance = 1 - 0.98 = 0.02
contingency_table_6c <- table(halloween_data$Classification, halloween_data$Preference..Chocolate)
contingency_table_6c
chi_sq_6c <- chisq.test(contingency_table_6c)
chi_sq_6c
# Interpretation 6c: If the p-value is less than 0.02, reject H0. We conclude there is a significant association between a student's classification and their chocolate preference.


# Question 7:

# H0: Observed distribution matches the expected distribution (p = c(0.13, 0.13, 0.14, 0.24, 0.20, 0.16))
# Ha: Observed distribution does not match the expected distribution.
# significance typically 0.05
observed_colors_7 <- c(355, 129, 243, 317, 178, 204)
expected_proportions_7 <- c(0.13, 0.13, 0.14, 0.24, 0.20, 0.16)

# Perform Chi-square goodness-of-fit test
chi_sq_7 <- chisq.test(observed_colors_7, p = expected_proportions_7)
chi_sq_7

# Interpretation 7: If the p-value is less than 0.05, reject H0. We conclude that the observed distribution of M&M's colors is significantly different from the manufacturer's expected distribution.
print(paste("Chi-Square Statistic:", chi_sq_7$statistic, 2))
print(paste("Degrees of Freedom:", chi_sq_7$parameter))
print(paste("P-value:", chi_sq_7$p.value))
