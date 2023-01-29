using TestingApi.Models;
using TestingApi.Services;
using Microsoft.AspNetCore.Mvc;

namespace TestingApi.Controllers;

[ApiController]
[Route("api/students")]
public class StudentsController: ControllerBase{
    private readonly StudentsService _studentsService;
    public StudentsController(StudentsService service) => 
        _studentsService = service;

    [HttpGet]
    public async Task<List<Student>> Get() =>
        await _studentsService.GetAsync();
    
    [HttpGet("{id:length(24)}")]
    public async Task<ActionResult<Student>> Get(string id){
        var student = await _studentsService.GetAsync(id);

        if(student is null){
            return NotFound();
        }

        return student;
    }

    [HttpPost]
    public async Task<IActionResult> Post(Student newStudent){
        await _studentsService.CreateAsync(newStudent);
        return CreatedAtAction(nameof(Get), new {id = newStudent.Id}, newStudent);
    }

    [HttpPut("id:length{24}")]

    public async Task<IActionResult> Update(string id, Student newStudent){
        var student = await _studentsService.GetAsync(id);

        if(student is null){
            return NotFound();
        }

        newStudent.Id = student.Id;
        await _studentsService.UpdateAsync(id, newStudent);
        return NoContent();
    }

    [HttpDelete("{id:length(24)}")]
    public async Task<IActionResult> Delete(string id){
        var student = _studentsService.GetAsync(id);

        if(student is null){
            return NotFound();
        }

        await _studentsService.RemoveAsync(id);
        return NoContent();
    }
}