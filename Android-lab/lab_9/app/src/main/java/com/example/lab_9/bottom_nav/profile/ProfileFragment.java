package com.example.lab_9.bottom_nav.profile;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.example.lab_9.bottom_nav.BaseFragment;
import com.example.lab_9.databinding.FragmentProfileBinding;
import com.example.lab_9.models.User;

public class ProfileFragment extends BaseFragment<FragmentProfileBinding> {
    @Override
    protected FragmentProfileBinding inflateBinding(LayoutInflater inflater, ViewGroup container) {
        return FragmentProfileBinding.inflate(inflater, container, false);
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        setupListeners();
        observeData();
    }

    private void setupListeners() {
        binding.logoutButton.setOnClickListener(v -> logout());
    }

    private void observeData() {
        userViewModel.getCurrentUser().observe(getViewLifecycleOwner(), user -> {
            if (user != null) {
                updateUserInfo(user);
            }
        });
    }

    private void updateUserInfo(User user) {
        if (user != null) {
            binding.usernameText.setText(user.getUsername());
            binding.emailText.setText(user.getEmail());
        }
    }

    private void logout() {
        userViewModel.logout();
    }
}