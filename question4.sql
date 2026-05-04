SELECT
    Students.StudentId,
    Students.FirstName,
    Students.LastName,
    Courses.CourseName
FROM Students
JOIN Enrolments
    ON Students.StudentId = Enrolments.StudentId
JOIN Courses
    ON Enrolments.CourseId = Courses.CourseId;