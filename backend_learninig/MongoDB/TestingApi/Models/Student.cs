using MongoDB.Bson;
using MongoDB.Bson.Serialization.Attributes;
using System.Text.Json.Serialization;

namespace TestingApi.Models;

public class Student{
    [BsonId]
    [BsonRepresentation(BsonType.ObjectId)]
    public string? Id {get; set;}
    [BsonElement("Group")]
    [JsonPropertyName("Group")]
    public string? Group {get; set;}
    [BsonElement("Student")]
    [JsonPropertyName("Name")]
    public string? Name {get; set;}
    [BsonElement("Mark")]
    [JsonPropertyName("Mark")]
    public double Mark {get; set;}
}
