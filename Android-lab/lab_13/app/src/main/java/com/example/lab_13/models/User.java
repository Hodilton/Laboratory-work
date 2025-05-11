package com.example.lab_13.models;

public class User {
    private String username;
    private String email;
    private String passwordHash;
    private String phone;
    private String birthday;

    public User() {}

    public User(String username, String email, String passwordHash, String phone, String birthday) {
        this.username = username;
        this.email = email;
        this.passwordHash = passwordHash;
        this.phone = phone;
        this.birthday = birthday;
    }

    public String getUsername() { return username; }
    public String getEmail() { return email; }
    public String getPasswordHash() { return passwordHash; }
    public String getPhone() { return phone; }
    public String getBirthday() { return birthday; }

    public void setUsername(String username) { this.username = username; }
    public void setEmail(String email) { this.email = email; }
    public void setPasswordHash(String passwordHash) { this.passwordHash = passwordHash; }
    public void setPhone(String phone) { this.phone = phone; }
    public void setBirthday(String birthday) { this.birthday = birthday; }
}