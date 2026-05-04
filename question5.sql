SELECT
    Students.StudentId,
    Students.FirstName,
    Students.LastName,
    SUM(Courses.Credits) AS TotalCreditsPassed
FROM Students
JOIN Enrolments
    ON Students.StudentId = Enrolments.StudentId
JOIN Courses
    ON Enrolments.CourseId = Courses.CourseId
WHERE Enrolments.Grade >= 40
GROUP BY
    Students.StudentId,
    Students.FirstName,
    Students.LastName;