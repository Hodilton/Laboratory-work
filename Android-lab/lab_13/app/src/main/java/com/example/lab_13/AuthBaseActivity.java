package com.example.lab_13;

import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.widget.*;
import android.widget.Toast;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public abstract class AuthBaseActivity extends AppCompatActivity {

    protected EditText emailEt, passwordEt, usernameEt, phoneEt, birthdayEt, confirmPasswordEt;
    protected ProgressBar progressBar;
    protected Button actionBtn;
    protected View backBtn;
    protected CheckBox rememberMeCb;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getLayoutResource();
        initViews();
        setupListeners();
    }

    protected abstract void getLayoutResource();
    protected abstract void initViews();
    protected abstract void setupListeners();
    protected abstract void performAuthAction();

    protected void setLoadingState(boolean isLoading) {
        progressBar.setVisibility(isLoading ? View.VISIBLE : View.GONE);
        actionBtn.setEnabled(!isLoading);
        if (backBtn != null) backBtn.setEnabled(!isLoading);
    }

    protected boolean validateField(EditText field, String value, String error, boolean condition) {
        if (condition) {
            field.setError(error);
            return false;
        }
        return true;
    }

    protected boolean validateEmail(String email) {
        return validateField(emailEt, email, "Email is required", email.isEmpty()) &&
                validateField(emailEt, email, "Valid email required",
                        !android.util.Patterns.EMAIL_ADDRESS.matcher(email).matches());
    }

    protected boolean validatePassword(String password) {
        return validateField(passwordEt, password, "Password is required", password.isEmpty()) &&
                validateField(passwordEt, password, "Password must be at least 6 characters", password.length() < 6);
    }

    protected boolean validateUsername(String username) {
        return usernameEt == null || !username.isEmpty() ||
                validateField(usernameEt, username, "Username is required", true);
    }

    protected boolean validatePhone(String phone) {
        return validateField(phoneEt, phone, "Format: +7 (XXX) XXX-XX-XX",
                !phone.matches("^\\+7\\s\\(\\d{3}\\)\\s\\d{3}-\\d{2}-\\d{2}$"));
    }

    protected boolean validateBirthday(String birthday) {
        try {
            SimpleDateFormat sdf = new SimpleDateFormat("dd.MM.yyyy");
            sdf.setLenient(false);
            Date birthDate = sdf.parse(birthday);
            Calendar cal = Calendar.getInstance();
            cal.add(Calendar.YEAR, -18);
            if (birthDate.after(cal.getTime())) {
                birthdayEt.setError("You must be at least 18 years old");
                return false;
            }
        } catch (ParseException e) {
            birthdayEt.setError("Format: dd.MM.yyyy");
            return false;
        }
        return true;
    }

    protected boolean validatePasswordConfirmation(String password, String confirmPassword) {
        return validateField(confirmPasswordEt, confirmPassword, "Passwords don't match", !password.equals(confirmPassword));
    }

    protected void handleAuthError(String message) {
        runOnUiThread(() -> {
            clearErrors();
            String lowerMsg = message.toLowerCase();

            if (lowerMsg.contains("password") && passwordEt != null) passwordEt.setError(message);
            else if (lowerMsg.contains("email") && emailEt != null) emailEt.setError(message);
            else if (lowerMsg.contains("username") && usernameEt != null) usernameEt.setError(message);
            else if (lowerMsg.contains("phone") && phoneEt != null) phoneEt.setError(message);
            else if (lowerMsg.contains("birthday") && birthdayEt != null) birthdayEt.setError(message);
            else Toast.makeText(this, message, Toast.LENGTH_LONG).show();
        });
    }

    private void clearErrors() {
        if (emailEt != null) emailEt.setError(null);
        if (passwordEt != null) passwordEt.setError(null);
        if (usernameEt != null) usernameEt.setError(null);
        if (phoneEt != null) phoneEt.setError(null);
        if (birthdayEt != null) birthdayEt.setError(null);
        if (confirmPasswordEt != null) confirmPasswordEt.setError(null);
    }

    protected static class PhoneNumberTextWatcher implements TextWatcher {
        private final EditText phoneEt;
        private boolean isFormatting;

        public PhoneNumberTextWatcher(EditText phoneEt) {
            this.phoneEt = phoneEt;
        }

        @Override public void beforeTextChanged(CharSequence s, int start, int count, int after) {}
        @Override public void onTextChanged(CharSequence s, int start, int before, int count) {}

        @Override
        public void afterTextChanged(Editable s) {
            if (isFormatting) return;
            isFormatting = true;

            String digits = s.toString().replaceAll("\\D", "");
            if (digits.length() > 11) digits = digits.substring(0, 11);

            StringBuilder formatted = new StringBuilder("+7 ");
            if (digits.startsWith("7")) digits = digits.substring(1);
            if (digits.length() >= 1) formatted.append("(").append(digits.substring(0, Math.min(3, digits.length())));
            if (digits.length() >= 4) formatted.append(") ").append(digits.substring(3, Math.min(6, digits.length())));
            if (digits.length() >= 7) formatted.append("-").append(digits.substring(6, Math.min(8, digits.length())));
            if (digits.length() >= 9) formatted.append("-").append(digits.substring(8, Math.min(10, digits.length())));

            phoneEt.removeTextChangedListener(this);
            phoneEt.setText(formatted.toString());
            phoneEt.setSelection(formatted.length());
            phoneEt.addTextChangedListener(this);
            isFormatting = false;
        }
    }
}