-- 学院（学院编号，学院名称） 3NF 
-- 比赛项目（项目编号，项目规则，项目名称，项目类型，制定人，制定日期，学 
-- 校编号） 3NF 
-- 运动员（运动员编号，姓名，性别，年龄，院系名称，遣派人数，运动队编号） 
-- 3NF 
-- 运动队（运动队编号，运动队名称）3NF 
-- 裁判员（裁判员编号，姓名，性别，岗位，项目编号）3NF 
-- 成绩（等级，排名，用户名，密码）3NF 
-- 报表（报表编号，报表名称，打印时间）3NF 
-- 报名（运动员编号，项目编号，比赛细则，人数限制）3NF 
-- 参加（运动员编号，项目编号，比赛地点，比赛时间，比赛人数）3NF 
-- 裁决（裁判员编号，项目编号，裁决人）3NF 


-- 评定（裁判员编号，项目编号，评定规则，评定人）3NF 

CREAT TABLE Class
(
    class_id       int unsigned    NOT NULL     AUTO_INCREMENT,
    class_name     char(50)        NOT NULL,
    PRIMARY KEY (school_id)
) ENGINE=InnoDB;

CREAT TABLE Sports
(
    sports_id       int unsigned    NOT NULL    AUTO_INCREMENT,
    sports_name     char(50)        NOT NULL,
    sports_score    int unsigned    NOT NULL DEFAULT 2,
    referee_id      int unsigned    NOT NULL,
    num_athletes    tinyint unsigned    NOT NULL,
    PRIMARY KEY (sports_id)
) ENGINE=InnoDB;

CREAT TABLE Athletes
(
    athletes_id     int unsigned    NOT NULL    AUTO_INCREMENT,
    athletes_name   char(50)        NOT NULL,
    athletes_sex    char(5)         NOT NULL,
    athletes_age    tinyint unsigned    NOT NULL,
    class_id        int unsigned    NOT NULL,
    PRIMARY KEY (athletes_id)
) ENGINE=InnoDB;

CREAT TABLE Referee
(
    referee_id      int unsigned    NOT NULL    AUTO_INCREMENT,
    referee_name    char(50)        NOT NULL,
    PRIMARY KEY (referee_id)
) ENGINE=InnoDB;

CREAT TABLE Registration
(
    sports_id       int unsigned    NOT NULL,
    athletes_id     int unsigned    NOT NULL,
    PRIMARY KEY (sports_id, athletes_id)
) ENGINE=InnoDB;
