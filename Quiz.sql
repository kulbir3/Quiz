CREATE TABLE Player(
    Player_id INTEGER PRIMARY KEY AUTOINCREMENT ,
    Name      TEXT NOT NULL ,
    Email     UNIQUE
    );
INSERT INTO Player (Name, Email) VALUES
    ('Alice', 'alice132@gmail.com'),
    ('Bob', 'bo23@gmail.com'),``
    ('Charlie', 'moist12@gamil.com');


CREATE TABLE Questions(
   questions_id INTEGER PRIMARY KEY AUTOINCREMENT ,
   questions    TEXT NOT NULL ,
   optionA      TEXT NOT NULL ,
   optionB      TEXT NOT NULL ,
   optionC      TEXT NOT NULL ,
   optionD      TEXT NOT NULL ,
   correct      CHAR(1) NOT NULL ,
   difficulty   TEXT    NOT NULL ,
   Category     TEXT    NOT NULL
);
INSERT INTO Questions (questions, optionA, optionB, optionC, optionD, correct, difficulty, Category) VALUES
('What is the capital of France?', 'Berlin', 'Madrid', 'Paris', 'Rome', 'C', 'Easy', 'Geography'),
('Which planet is known as the Red Planet?', 'Earth', 'Mars', 'Jupiter', 'Saturn', 'B', 'Easy', 'Science'),
('Who wrote "To Kill a Mockingbird"?', 'Harper Lee', 'Mark Twain', 'Ernest Hemingway', 'F. Scott Fitzgerald', 'A', 'Medium', 'Literature'),
('What is the largest ocean on Earth?', 'Atlantic Ocean', 'Indian Ocean', 'Arctic Ocean', 'Pacific Ocean', 'D', 'Medium', 'Geography'),
('What is the chemical symbol for gold?', 'Au', 'Ag', 'Fe', 'Pb', 'A', 'Hard', 'Science'),
('Who painted the Mona Lisa?', 'Vincent van Gogh', 'Pablo Picasso', 'Leonardo da Vinci', 'Claude Monet', 'C', 'Hard', 'Art');


CREATE TABLE Score(
    score_id INTEGER PRIMARY KEY AUTOINCREMENT ,
    Player_id INTEGER NOT NULL ,
    score INTEGER DEFAULT 0,
    date_played TEXT DEFAULT (datetime('now')),
    FOREIGN KEY (Player_id) REFERENCES Player(Player_id)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);
INSERT INTO Score(Player_id, score) VALUES
(1, 85),
(2, 90),
(3, 75);

SELECT * FROM Player;
SELECT * FROM Score;

SELECT * FROM Questions ORDER BY RANDOM() LIMIT 6;
SELECT * FROM Questions WHERE difficulty = 'Easy' ORDER BY RANDOM() LIMIT 6;
SELECT * FROM Questions WHERE difficulty = 'Medium' ORDER BY RANDOM() LIMIT 6;
SELECT * FROM Questions WHERE difficulty = 'Hard' ORDER BY RANDOM() LIMIT 6;
SELECT * FROM Questions WHERE Category = 'Science' ORDER BY RANDOM() LIMIT 6;
SELECT * FROM Questions WHERE Category = 'Geography' ORDER BY RANDOM() LIMIT 6;
SELECT * FROM Questions WHERE Category = 'Literature' ORDER BY RANDOM() LIMIT 6;
SELECT * FROM Questions WHERE Category = 'Art' ORDER BY RANDOM() LIMIT 6;


