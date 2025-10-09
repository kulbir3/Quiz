CREATE TABLE Questions(
                          question_id     INTEGER PRIMARY KEY AUTOINCREMENT ,
                          question_text   TEXT NOT NULL UNIQUE ,
                          optionA         Text NOT NULL ,
                          optionB         Text NOT NULL ,
                          optionC         Text NOT NULL ,
                          optionD         Text NOT NULL ,
                          correct_option  Char(1) NOT NULL,
                          difficulty      TEXT NOT NULL ,
                          category        TEXT NOT NULL
);

INSERT INTO Questions(question_text, optionA, optionB, optionC, optionD, correct_option, difficulty, category)
VALUES
    ('What is the capital of France?', 'Berlin', 'Madrid', 'Paris', 'Rome', 'C', 'Easy', 'Geography'),
    ('What is 2 + 2?', '3', '4', '5', '6', 'B', 'Easy', 'Maths'),
    ('Who wrote "Hamlet"?', 'Charles Dickens', 'Mark Twain', 'William Shakespeare', 'Jane Austen', 'C', 'Medium', 'Literature'),
    ('What is the largest planet in our solar system?', 'Earth', 'Mars', 'Jupiter', 'Saturn', 'C', 'Medium', 'Science'),
    ('What is the chemical symbol for water?', 'H2O', 'CO2', 'O2', 'NaCl', 'A', 'Easy', 'Science'),
    ('Who painted the Mona Lisa?', 'Vincent van Gogh', 'Pablo Picasso', 'Leonardo da Vinci', 'Claude Monet', 'C', 'Hard', 'Art'),
    ('What is the smallest prime number?', '0', '1', '2', '3', 'C', 'Easy', 'Maths'),
    ('In which year did the Titanic sink?', '1910', '1912', '1914', '1916', 'B', 'Medium', 'History');

CREATE TABLE Player(
                       Player_id  INTEGER PRIMARY KEY AUTOINCREMENT ,
                       Name       TEXT NOT NULL ,
                       email      TEXT UNIQUE
);

INSERT INTO Player(Name, email)
VALUES
    ('Alice', 'alic@gmail.com'),
    ('Bob', 'bo@gmail.com');



CREATE TABLE Score(
                      score_id INTEGER PRIMARY KEY AUTOINCREMENT,
                      Player_id INTEGER NOT NULL ,
                      score INTEGER NOT NULL DEFAULT 0,
                      date_played DATETIME DEFAULT CURRENT_TIMESTAMP,
                      FOREIGN KEY (Player_id) REFERENCES Player(Player_id)
                          ON DELETE CASCADE
                          ON DELETE RESTRICT
);


INSERT INTO Score(Player_id, score)
VALUES
    (1, 10),
    (2, 20);