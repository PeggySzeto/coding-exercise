# Coding Challenge

## The Challenge
Your task is to develop a small application. We need you to build your application in your own GitHub repository.  Please do not fork our repository to create your project.  Once you are done, send us a link to your repository.

Please allow yourself at least 1 hour of uninterrupted time for this task, but feel free to spend as much time on the task as you like and make the solution and the code as perfect as you like.

## The application
We would like you to develop an MVP application for a storage heater controller. The controller receives schedules via `STDIN` and needs to switch the storage heater on and off according to the schedule by printing either `ON` or `OFF` to `STDOUT` at the appropriate time.

The schedule is codified in a string of zeros and ones, where each digit represents the storage heater state for a half-hour period, and the whole string
contains 48 digits (one digit for each 30 minute period in the following 24 hours)

```
000000001010101011111111000011110000111111111111
```

The schedule can be updated at any time by entering a new schedule string on the console through STDIN. Hence, your application should be listening to STDIN in order to receive new schedule updates.

Some insights into what we'll be looking for (and what we will not):

- Please use an open source tool chain that's freely available so we can build your application
- Please specify any external dependencies that need to be installed in order to run your application (ideally keep these to a minimum if possible)
- Please include instructions on how to build and run your application
- Explicitly state any assumptions you make
- Feel free to commit as often as you'd like. The more commits the better! Please commit at least once within the first hour
- It's better to complete 1 task than to start 3
- We will be looking at how you structure your code to answer the questions
- The code you write should be suitable for production as far as possible within the time constraints (comments for what you might do given more time would be well received)
- We expect your code to be well tested and a TDD approach would be received well
- The code should be written with maintainability in mind

Good Luck!

