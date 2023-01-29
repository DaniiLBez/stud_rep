namespace TestingApi.Models;

public class TestingDatabaseSettings{
    public string ConnectionString {get;set;} = null!;
    public string DatabaseName {get; set;} = null!;
    public string StudentsCollectionName {get; set;} = null!;

}