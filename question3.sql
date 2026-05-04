SELECT
    Departments.DepartmentName,
    COUNT(Enrolments.EnrolmentId) AS TotalEnrolments
FROM Departments
JOIN Courses
    ON Departments.DepartmentId = Courses.DepartmentId
JOIN Enrolments
    ON Courses.CourseId = Enrolments.CourseId
GROUP BY Departments.DepartmentName;