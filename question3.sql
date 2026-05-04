SELECT
    Department.DepartmentName,
    COUNT(Enrolment.EnrolmentId) AS TotalEnrolments
FROM Department
JOIN Course
    ON Department.DepartmentId = Course.DepartmentId
JOIN Enrolment
    ON Course.CourseId = Enrolment.CourseId
GROUP BY Department.DepartmentName;