SELECT
    Student.StudentId,
    Student.FirstName,
    Student.LastName,
    Course.CourseName
FROM Student
JOIN Enrolment
    ON Student.StudentId = Enrolment.StudentId
JOIN Course
    ON Enrolment.CourseId = Course.CourseId;