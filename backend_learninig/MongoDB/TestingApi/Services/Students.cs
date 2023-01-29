using TestingApi.Models;
using Microsoft.Extensions.Options;
using MongoDB.Driver;

namespace TestingApi.Services;

public class StudentsService{
    private readonly IMongoCollection<Student> _studentsCollection;
    public StudentsService(IOptions<TestingDatabaseSettings> testingDatabaseSetting){
        var mongoClient = new MongoClient(
            testingDatabaseSetting.Value.ConnectionString);

        var mongoDatabase = mongoClient.GetDatabase(
            testingDatabaseSetting.Value.DatabaseName);
        
        _studentsCollection = mongoDatabase.GetCollection<Student>(
            testingDatabaseSetting.Value.StudentsCollectionName);
    }

    public async Task<List<Student>> GetAsync() => 
        await _studentsCollection.Find(_ => true).ToListAsync();
    
    public async Task<Student?> GetAsync(string id) =>
        await _studentsCollection.Find(x => x.Id == id).FirstOrDefaultAsync();

    public async Task CreateAsync(Student newStudent) =>
        await _studentsCollection.InsertOneAsync(newStudent);

    public async Task UpdateAsync(string id, Student newStudent) =>
        await _studentsCollection.ReplaceOneAsync(x => x.Id == id, newStudent);

    public async Task RemoveAsync(string id) =>
        await _studentsCollection.DeleteOneAsync(x => x.Id == id);

}



 